<script>
    import { getCrops, getNutrientsForCrop, isOk } from "$lib/functions";
    import { onMount } from "svelte";

    const { currentValues, currentCrop } = $props();

    const makeData = async (selectedCrop) => {
        const rangeValues = await getNutrientsForCrop(selectedCrop);
        const _data = {};

        for (const key in rangeValues) {
            _data[key] = {
                current: currentValues[key],
                optimal: (rangeValues[key].max + rangeValues[key].min) / 2,
                ok: isOk(currentValues[key], rangeValues[key]),
            };
        }
        return _data;
    };

    onMount(async () => {
        allCrops = await getCrops();
        const crop = allCrops.crops[0];
        data = await makeData(crop);
        selectedCrop = crop;
    });

    let selectedCrop = $state();
    let allCrops = $state();
    let data = $state();

    $effect(async () => {
        if (selectedCrop !== undefined) {
            data = await makeData(selectedCrop);
        }
    });
</script>

{#if data !== undefined}
    <div
        class="w-full rounded-lg p-4 sm:p-4 md:p-4"
        style="background-color: var(--color-background); color: var(--color-text);"
    >
        <h2 class="text-center text-lg font-bold" style="color: var(--color-primary);">Plant Information</h2>

        <div class="flex flex-col gap-4 rounded-md p-4" style="background-color: white;">
            <!-- Dropdown Row -->
            <div class="flex flex-col sm:flex-row sm:items-center sm:gap-2">
                <div
                    class="mb-2 text-lg font-semibold whitespace-nowrap sm:mb-0 sm:pr-4"
                    style="color: var(--color-primary);"
                >
                    Choose Plant:
                </div>
                <select
                    bind:value={selectedCrop}
                    class="w-full rounded px-4 py-2 text-center shadow sm:max-w-40"
                    style="background-color: var(--color-accent); color: var(--color-text); border: 1px solid var(--color-secondary);"
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
                            class="h-full w-full rounded-xl border-2 px-2 py-2 text-center transition"
                            style="border-color: {nutrientData.ok ? 'var(--color-primary)' : 'var(--color-error)'}; 
                                   background-color: {nutrientData.ok
                                ? 'var(--color-accent)'
                                : 'rgba(186, 24, 27, 0.2)'};"
                        >
                            <div
                                class="text-lg font-bold capitalize"
                                style="color: {nutrientData.ok ? 'var(--color-primary)' : 'var(--color-error)'};"
                            >
                                {nutrientName}
                            </div>

                            <!-- Scrollable container -->
                            <div class="mt-1 flex gap-4 px-1">
                                {#each ["current", "optimal"] as key}
                                    <div
                                        class="min-w-[100px] shrink-0 grow text-sm font-medium capitalize"
                                        style="color: var(--color-text);"
                                    >
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
{/if}

<style>
    :global(:root) {
        --color-text: #040316;
        --color-primary: #276252;
        --color-background: #e5e5e5;
        --color-secondary: #6a9587;
        --color-accent: #abd3bb;
        --color-error: #ba181b;
    }
</style>
