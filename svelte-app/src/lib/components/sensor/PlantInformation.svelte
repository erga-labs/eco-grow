<script>
    import { getNutrientsForCrop } from "$lib/functions";

    let selectedCrop = $state("Tomato");
    let nutrients = $derived(getNutrientsForCrop(selectedCrop));
</script>

<div class="w-full rounded-lg bg-gray-200 p-8">
    <h2 class="mb-2 text-center text-lg font-bold">Plant Information</h2>

    <div class="flex flex-col gap-4 rounded-md bg-gray-300 p-4">
        <div class="flex h-12 items-center justify-start gap-2">
            <div class="w-fit pr-4 text-lg font-semibold whitespace-nowrap">Choose Plant:</div>
            <select bind:value={selectedCrop} class="w-full max-w-40 rounded bg-green-200 px-4 py-2 text-center shadow">
                {#each ["Tomato", "Apple"] as plant}
                    <option value={plant}>{plant}</option>
                {/each}
            </select>
        </div>

        <div class="flex gap-3">
            {#each Object.entries(nutrients) as [nutrientName, nutrientData]}
                <div class="h-auto grow">
                    <div
                        class={`h-full w-full rounded-xl border-3 text-center transition ${nutrientData.ok ? "border-emerald-500 bg-emerald-400" : "border-orange-500 bg-orange-400"} py-1`}
                    >
                        <div class="text-lg font-bold capitalize">{nutrientName}</div>
                        <div class="flex">
                            {#each ["current", "optimal"] as key}
                                <div class="grow capitalize">{key}: {nutrientData[key]}</div>
                            {/each}
                        </div>
                    </div>
                </div>
            {/each}
        </div>
    </div>
</div>
