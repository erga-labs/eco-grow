<script>
    import { getCrops, getNutrientsForCrop, isOk } from "$lib/functions";

    const { currentValues, currentCrop } = $props();
    const allCrops = getCrops();

    const makeData = (selectedCrop) => {
        const optimalValues = getNutrientsForCrop(selectedCrop);
        const _data = {};

        for (const key in optimalValues) {
            _data[key] = {
                current: currentValues[key],
                optimal: optimalValues[key],
                ok: isOk(currentValues[key], optimalValues[key]),
            };
        }
        return _data;
    };

    let selectedCrop = $state(allCrops[0]);
    let data = $derived(makeData(selectedCrop));
</script>


<div class="w-full rounded-lg bg-gray-200 p-4 sm:p-4 md:p-4">
    <h2 class="text-center text-lg font-bold">Plant Information</h2>

    <div class="flex flex-col gap-4 rounded-md bg-gray-300 p-4">
        <!-- Dropdown Row -->
        <div class="flex flex-col sm:flex-row sm:items-center sm:gap-2">
            <div class="mb-2 sm:mb-0 sm:pr-4 text-lg font-semibold whitespace-nowrap">Choose Plant:</div>
            <select bind:value={selectedCrop} class="w-full sm:max-w-40 rounded bg-green-200 px-4 py-2 text-center shadow">
                {#each allCrops as crop}
                    <option value={crop}>{crop}</option>
                {/each}
            </select>
        </div>

        <!-- Nutrient Cards Row -->
        <div class="flex flex-col gap-3 sm:flex-row sm:flex-wrap">
            {#each Object.entries(data) as [nutrientName, nutrientData]}
                <div class="w-full sm:w-[48%]">
                    <div
                        class={`h-full w-full rounded-xl border-3 text-center transition ${nutrientData.ok ? "border-emerald-500 bg-emerald-400" : "border-orange-500 bg-orange-400"} py-2 px-2`}
                    >
                        <div class="text-lg font-bold capitalize">{nutrientName}</div>

                        <!-- Scrollable container -->
                        <div class="flex gap-4 mt-1 px-1 justify-items-center">
                            {#each ["current", "optimal"] as key}
                                <div class="min-w-[100px] shrink-0 capitalize text-sm font-medium">
                                    {key}: {nutrientData[key]}
                                </div>
                            {/each}
                        </div>
                    </div>
                </div>
            {/each}
        </div>
    </div>
</div>
