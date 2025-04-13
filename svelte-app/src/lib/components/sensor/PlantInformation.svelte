<script>
    let nutrients = [
        { key: "N", label: "N", tooltip: "Nitrogen", color: "bg-red-600" },
        { key: "P", label: "P", tooltip: "Phosphorus", color: "bg-emerald-800" },
        { key: "K", label: "K", tooltip: "Potassium", color: "bg-emerald-800" },
        { key: "M%", label: "M%", tooltip: "Moisture %", color: "bg-emerald-800" }
    ];
    
    let plants = [
        "Tomato",
        "Onion",
        "Apple",
    ];

    // TODO: fetch from api
    let selectedPlant = plants[0];
  
  
  </script>
  
  <!-- <style>
    .tooltip {
      @apply absolute left-1/2 transform -translate-x-1/2 text-xs bg-purple-700 text-white px-2 py-1 rounded z-10 shadow-md;
    }
  </style> -->
  
  <div class="p-4 bg-gray-200 rounded-lg w-fit">
    <h2 class="font-semibold mb-2">Plant Information</h2>
  
    <div class="flex gap-4 flex-col bg-gray-300 p-4 rounded-md">
      <!-- Plant Dropdown -->
      <div class="flex items-center gap-2 justify-start">
        <select bind:value={selectedPlant} class="px-4 py-2 bg-green-200 rounded shadow">
            {#each plants as plant}
            <option value={plant}>{plant}</option>
            {/each}
            <!-- Add more options as needed -->
        </select>

      </div>
      
      <div class="flex gap-3">

          <!-- Nutrient Buttons -->
          {#each nutrients as nutrient (nutrient.key)}
            <div class="relative group">
              <button class={`w-12 h-12 text-white font-bold rounded ${nutrient.color}`}>
                {nutrient.label}
              </button>
              <!-- Tooltip -->
              <div class="tooltip opacity-0 group-hover:opacity-100 transition">
                {nutrient.label}
              </div>
            </div>
          {/each}

      </div>
    </div>
  </div>
  