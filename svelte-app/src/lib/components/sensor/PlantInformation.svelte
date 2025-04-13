<script>
    let nutrients = [
        { key: "N", label: "N", tooltip: "Nitrogen", color: "bg-red-600" },
        {
            key: "P",
            label: "P",
            tooltip: "Phosphorus",
            color: "bg-emerald-800",
        },
        { key: "K", label: "K", tooltip: "Potassium", color: "bg-emerald-800" },
        {
            key: "M%",
            label: "M%",
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

<div class="w-fit rounded-lg bg-gray-200 p-4">
    <h2 class="mb-2 font-semibold">Plant Information</h2>

    <div class="flex flex-col gap-4 rounded-md bg-gray-300 p-4">
        <!-- Plant Dropdown -->
        <div class="flex items-center justify-start gap-2">
            <select
                bind:value={selectedPlant}
                class="rounded bg-green-200 px-4 py-2 shadow"
            >
                {#each plants as plant}
                    <option value={plant}>{plant}</option>
                {/each}
                <!-- Add more options as needed -->
            </select>
        </div>

        <div class="flex gap-3">
            <!-- Nutrient Buttons -->
            {#each nutrients as nutrient (nutrient.key)}
                <div class="group relative">
                    <button
                        class={`h-12 w-12 rounded font-bold text-white ${nutrient.color}`}
                    >
                        {nutrient.label}
                    </button>
                    <!-- Tooltip -->
                    <div
                        class="tooltip opacity-0 transition group-hover:opacity-100"
                    >
                        {nutrient.label}
                    </div>
                </div>
            {/each}
        </div>
    </div>
</div>
