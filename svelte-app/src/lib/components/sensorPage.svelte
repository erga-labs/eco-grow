<script>
    import GraphComponent from "$lib/components/sensor/GraphComponent.svelte";
    import PlantInformation from "$lib/components/sensor/PlantInformation.svelte";
    export let selectedSensor = "";
</script>

<!-- Outer container -->
<div class="min-h-full w-full overflow-auto rounded-lg bg-red-400 px-8">
    <p class="px-2 pb-2 text-lg font-semibold text-white">
        Selected Sensor: {selectedSensor}
    </p>

    <!-- Graph wrapper: 1/2 screen on md+, full screen on small -->
    <div class="flex gap-4 md:flex-col md:gap-8 lg:flex-row">
        <div
            class="h-full w-full flex-3/4 rounded-l bg-amber-50
                    px-3 md:h-1/2 md:w-1/2"
        >
            <GraphComponent />
        </div>

        <div class="h-full w-full md:h-1/2 md:w-1/2">
            <PlantInformation />
        </div>
    </div>
</div>
