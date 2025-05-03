<script>
    // import { area, curveLinear, Delaunay, range, scaleLinear, scaleUtc } from 'd3';
    import { area, curveLinear } from "d3-shape";
    import { Delaunay } from "d3-delaunay";
    import { range } from "d3-array";
    import { scaleLinear, scaleUtc } from "d3-scale";

    import data from "./area-data";

    const marginTop = 40; // the top margin, in pixels
    const marginRight = 10; // the right margin, in pixels
    const marginBottom = 30; // the bottom margin, in pixels
    const marginLeft = 50; // the left margin, in pixels
    const inset = 0; // inset the default range, in pixels
    const width = 599; // the outer width of the chart, in pixels
    const height = 350; // the outer height of the chart, in pixels
    const xLabel = ""; // a label for the y-axis
    const yLabel = "↑ Sensor Data"; // a label for the y-axis
    const xFormat = ""; // a format specifier string for the y-axis
    const yFormat = "mg/kg"; // a format specifier string for the y-axis
    const horizontalGrid = false; // show horizontal grid lines
    const verticalGrid = false; // show vertical grid lines
    const colors = ["red", "blue", "green", "yellow"]; // fill color for dots && number of colors in fill array MUST match number of subsets in data
    const showDots = true; // whether dots should be displayed
    const dotsFilled = true; // whether dots should be filled or outlined
    const r = 2; // (fixed) radius of dots, in pixels
    const strokeWidth = 2; // stroke width of line, in pixels
    const fillOpacity = 0.3; // fill opacity of area
    const tooltipBackground = "#181818aa"; // background color of tooltip
    const tooltipTextColor = "white"; // text color of tooltip
    const strokeLinecap = "round"; // stroke line cap of the line
    const strokeLinejoin = "round"; // stroke line join of the line
    const xScalefactor = width / 80; //y-axis number of values
    const yScalefactor = height / 40; //y-axis number of values
    const curve = curveLinear; // method of interpolation between points
    const xType = scaleUtc; // type of x-scale

    // Function to format time as hours ago
    function formatTimeAgo(date) {
        const hoursAgo = Math.round((new Date() - date) / (1000000 * 60 * 8 * 60 * 60));
        return hoursAgo + "hr" + (hoursAgo !== 1 ? "s" : "") + " ago";
    }
    const insetTop = inset; // inset from top
    const insetRight = inset; // inset from right
    const insetBottom = inset; // inset fro bottom
    const insetLeft = inset; // inset from left
    const xRange = [marginLeft + insetLeft, width - marginRight - insetRight]; // [left, right]
    const yType = scaleLinear; // type of y-scale
    const yRange = [height - marginBottom - insetBottom, marginTop + insetTop]; // [bottom, top]

    // Initialize dotInfo as null
    let dotInfo = null;

    let x,
        y,
        areas,
        filteredI,
        xVals = [],
        yVals = [],
        points = [],
        subsets = [],
        colorVals = [];

    // For a single set of data
    if (!("data" in data[0])) {
        x = Object.keys(data[0])[0];
        y = Object.keys(data[0])[1];
        xVals = data.map((el) => el[x]);
        yVals = data.map((el) => el[y]);
        colorVals = data.map((el) => 0);
        points = data.map((el) => ({
            x: el[x],
            y: el[y],
            color: 0,
        }));
    }
    // For data with subsets (NOTE: expects 'id' and 'data' keys)
    else {
        x = Object.keys(data[0]?.data[0])[0];
        y = Object.keys(data[0]?.data[0])[1];
        data.forEach((subset, i) => {
            subset.data.forEach((coordinate) => {
                xVals.push(coordinate[x]);
                yVals.push(coordinate[y]);
                colorVals.push(i);
                points.push({
                    x: coordinate[x],
                    y: coordinate[y],
                    color: i,
                });
            });
            subsets.push(subset.id);
        });
    }

    const I = range(xVals.length);
    const gaps = (d, i) => !isNaN(xVals[i]) && !isNaN(yVals[i]);
    const cleanData = points.map(gaps);
    const xDomain = [xVals[0], xVals[xVals.length - 1]];
    const yDomain = [0, Math.max(...yVals)];
    const xScale = xType(xDomain, xRange);
    const yScale = yType(yDomain, yRange);
    const niceY = scaleLinear()
        .domain([0, Math.max(...yVals)])
        .nice();
    const chartArea = area()
        .defined((i) => cleanData[i])
        .curve(curve)
        .x((i) => xScale(xVals[i]))
        .y0(yScale(0))
        .y1((i) => yScale(yVals[i]));

    $: {
        areas = [];
        colors.forEach((color, j) => {
            filteredI = [];
            filteredI = I.filter((el, i) => colorVals[i] === j);
            areas.push(chartArea(filteredI));
        });
    }

    const pointsScaled = points.map((el) => [xScale(el.x), yScale(el.y), el.color]);
    const delaunayGrid = Delaunay.from(pointsScaled);
    const voronoiGrid = delaunayGrid.voronoi([0, 0, width, height]);

    const xTicks = xScale.ticks(xScalefactor);
    // Format time as hours ago
    const xTicksFormatted = xTicks.map((date) => {
        const hoursAgo = Math.round((new Date() - date) / (1000 * 60 * 60));
        return hoursAgo + "hr" + (hoursAgo !== 1 ? "s" : "") + " ago";
    });
    const yTicks = niceY.ticks(yScalefactor);

    // Function to handle mouse over events
    function handleMouseOver(point, i, event) {
        dotInfo = [point, i, event];
    }

    // Function to handle mouse out events
    function handleMouseOut() {
        dotInfo = null;
    }
</script>

<div class="bg-amber-50 px-2">
    <svg class="" viewBox="0 0 {width} {height}" on:mouseout={handleMouseOut} on:blur={handleMouseOut} role="img">
        <!-- Dots -->
        {#if showDots && !dotInfo}
            {#each I as i}
                <g class="pointer-events-none">
                    <circle
                        cx={xScale(xVals[i])}
                        cy={yScale(yVals[i])}
                        {r}
                        stroke={colors[colorVals[i]]}
                        fill={colors[colorVals[i]]}
                    />
                </g>
            {/each}
        {/if}

        <!-- Chart Areas -->
        {#each areas as subsetArea, i}
            <g class="pointer-events-none">
                {#if dotInfo}
                    <path
                        class="line"
                        fill={colors[i]}
                        fill-opacity={points[dotInfo[1]].color === i ? "0.5" : "0.1"}
                        stroke={colors[i]}
                        d={subsetArea}
                    />
                    <circle
                        cx={xScale(points[dotInfo[1]].x)}
                        cy={yScale(points[dotInfo[1]].y)}
                        r="3"
                        stroke={colors[points[dotInfo[1]].color]}
                        fill="none"
                    />
                {:else}
                    <path
                        class="line"
                        fill={colors[i]}
                        stroke={colors[i]}
                        d={subsetArea}
                        fill-opacity={fillOpacity}
                        stroke-width={strokeWidth}
                        stroke-linecap={strokeLinecap}
                        stroke-linejoin={strokeLinejoin}
                    />
                {/if}
            </g>
        {/each}

        <!-- Y-Axis -->
        <g class="pointer-events-none" transform="translate({marginLeft}, 0)">
            <path class="stroke-black" d="M{insetLeft}, {marginTop} V{height - marginBottom + 6}" />
            {#each yTicks as tick}
                <g transform="translate(0, {yScale(tick)})" class="font-sans text-[10px] text-black">
                    <line x1={insetLeft - 6} x2={insetLeft} class="stroke-black" />
                    {#if horizontalGrid}
                        <line x1={insetLeft} x2={width - marginLeft - marginRight} class="stroke-black opacity-20" />
                    {/if}
                    <text x="-{marginLeft}" y="5" class="text-black">{tick + yFormat}</text>
                </g>
            {/each}
            <text x="-{marginLeft}" y={marginTop - 10} class="text-black">{yLabel}</text>
        </g>

        <!-- X-Axis -->
        <g class="pointer-events-none" transform="translate(0,{height - marginBottom - insetBottom})">
            <path class="stroke-black" d="M{marginLeft},0.5 H{width - marginRight}" />
            {#each xTicks as tick, i}
                <g transform="translate({xScale(tick)}, 0)" class="font-sans text-[10px] text-black">
                    <line y2="6" class="stroke-black" />
                    {#if verticalGrid}
                        <line y2={-height} class="stroke-black opacity-20" />
                    {/if}
                    <text x={-marginLeft / 4} y="20" class="text-black">{xFormat}</text>
                </g>
            {/each}
            <text x={width - marginLeft - marginRight - 40} y={marginBottom} class="text-black">{xLabel}</text>
        </g>

        <!-- Voronoi interaction overlay -->
        {#each pointsScaled as point, i}
            <path
                d={voronoiGrid.renderCell(i)}
                stroke="none"
                fill-opacity="0"
                on:mouseover={(e) => handleMouseOver(point, i, e)}
                on:focus={(e) => handleMouseOver(point, i, e)}
                role="button"
                tabindex="0"
            />
        {/each}
    </svg>
</div>

<!-- Tooltip -->
{#if dotInfo}
    <div
        class="fixed z-50 rounded-md px-2 py-1 text-sm shadow-lg"
        style="
        left: {dotInfo[2].clientX + 12}px;
        top: {dotInfo[2].clientY + 12}px;
        background-color: {tooltipBackground};
        color: {tooltipTextColor};
        pointer-events: none;
      "
    >
        {subsets ? subsets[points[dotInfo[1]].color] : ""}:
        {formatTimeAgo(points[dotInfo[1]].x)}: {points[dotInfo[1]].y.toFixed(2)}{yFormat}
    </div>
{/if}
