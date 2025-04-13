<script>
    let nutrients = [
        { key: "Nitrogen", label: "Nitrogen", tooltip: "Nitrogen", color: "bg-red-600" },
        {
            key: "Phosphorus",
            label: "Phosphorus",
            tooltip: "Phosphorus",
            color: "bg-emerald-800",
        },
        { key: "Potassium", label: "Potassium", tooltip: "Potassium", color: "bg-emerald-800" },
        {
            key: "Moisture %",
            label: "Moisture %",
            tooltip: "Moisture %",
            color: "bg-emerald-800",
        },
    ];

    let plants = ["Tomato", "Onion", "Apple"];

    // TODO: fetch from api
    let selectedPlant = plants[0];
</script>

<!-- <style>
    .tooltip {
      @apply absolute left-1/2 transform -translate-x-1/2 text-xs bg-purple-700 text-white px-2 py-1 rounded z-10 shadow-md;
    }
  </style> -->

<div class="w-full rounded-lg bg-gray-200 p-8">
    <h2 class="mb-2 text-center text-lg font-bold">Plant Information</h2>

    <div class="flex flex-col gap-4 rounded-md bg-gray-300 p-4">
        <!-- Plant Dropdown -->
        <div class="flex h-12 items-center justify-start gap-2">
            <div class="w-fit pr-4 text-lg font-semibold whitespace-nowrap">Choose Plant:</div>
            <select bind:value={selectedPlant} class="w-full rounded bg-green-200 px-4 py-2 text-center shadow">
                {#each plants as plant}
                    <option value={plant}>{plant}</option>
                {/each}
            </select>
        </div>

        <div class="flex gap-3">
            <!-- Nutrient Buttons -->
            {#each nutrients as nutrient (nutrient.key)}
                <div class="grow">
                    <button class={`h-full w-full rounded-xl font-bold text-white ${nutrient.color}`}>
                        {nutrient.label}
                    </button>
                    <!-- Tooltip -->
                    <div class="tooltip opacity-0 transition group-hover:opacity-100">
                        {nutrient.label}
                    </div>
                </div>
            {/each}
        </div>
    </div>
</div>
