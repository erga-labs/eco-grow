<script>
    import { getCrops, getNutrientsForCrop, isOk } from "$lib/functions";

    const { currentValues, currentCrop } = $props();
    const allCropsPromise = getCrops();

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

    let selectedCrop = $state(allCropsPromise[0]);
    let data = $derived(makeData(selectedCrop));
</script>

{#await allCropsPromise then allCrops}
    <div class="w-full rounded-lg bg-gray-200 p-4 sm:p-4 md:p-4">
        <h2 class="text-center text-lg font-bold">Plant Information</h2>

        <div class="flex flex-col gap-4 rounded-md bg-gray-300 p-4">
            <!-- Dropdown Row -->
            <div class="flex flex-col sm:flex-row sm:items-center sm:gap-2">
                <div class="mb-2 text-lg font-semibold whitespace-nowrap sm:mb-0 sm:pr-4">Choose Plant:</div>
                <select
                    bind:value={selectedCrop}
                    class="w-full rounded bg-green-200 px-4 py-2 text-center shadow sm:max-w-40"
                >
                    {#each allCrops.crops as crop}
                        <option value={crop}>{crop}</option>
                    {/each}
                </select>
            </div>

            <!-- Nutrient Cards Row -->
            <div class="flex flex-col gap-3 sm:flex-row sm:flex-wrap">
                {#each Object.entries(data) as [nutrientName, nutrientData]}
                    <div class="w-full sm:w-[48%]">
                        <div
                            class={`h-full w-full rounded-xl border-3 text-center transition ${nutrientData.ok ? "border-emerald-500 bg-emerald-400" : "border-orange-500 bg-orange-400"} px-2 py-2`}
                        >
                            <div class="text-lg font-bold capitalize">{nutrientName}</div>

                            <!-- Scrollable container -->
                            <div class="mt-1 flex gap-4 px-1">
                                {#each ["current", "optimal"] as key}
                                    <div class="min-w-[100px] shrink-0 grow text-sm font-medium capitalize">
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
{:catch error}
    <p style="color: red">{error.message}</p>
{/await}
