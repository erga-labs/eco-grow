<script>
  import SidebarItem from "./sidebarItem.svelte";
  import { CircleUserRound } from "@lucide/svelte";
  
  export let ids = [];
  export let onCpuClick;
  
  // Add a variable to track the currently selected ID
  let selectedId = null;
  
  // Function to handle when a CPU is clicked
  function handleCpuClick(id) {
    selectedId = id; // Update the selected ID
    onCpuClick(id); // Call the original click handler
  }
</script>

<div class="w-auto px-2.5 h-full bg-red-300">
  <div class="flex flex-col justify-between h-full py-4 items-center">
    <div class="flex flex-col gap-4">
      {#each ids as id}
        <SidebarItem 
          id={id}
          isSelected={id === selectedId}
          on:click={() => handleCpuClick(id)}
        />
      {/each}
    </div>
    <div class="aspect-square bg-green-500 p-2 rounded-md border-2 border-green-300 flex justify-center items-center">
      <CircleUserRound />
    </div>
  </div>
</div>