<script>
    import SidebarItem from "./sidebarItem.svelte";
    import { CircleUserRound } from "@lucide/svelte";

    export let ids = [];
    export let onCpuClick;

    let selectedId = null;

    // Function to handle when a CPU is clicked
    function handleCpuClick(id) {
        selectedId = id; // Update the selected ID
        onCpuClick(id); // Call the original click handler
    }
</script>

<div class="h-full w-auto bg-red-300 px-2.5">
    <div class="flex h-full flex-col items-center justify-between py-4">
        <div class="flex flex-col gap-4">
            {#each ids as id}
                <SidebarItem
                    {id}
                    isSelected={id === selectedId}
                    on:click={() => handleCpuClick(id)}
                />
            {/each}
        </div>
        <div
            class="flex aspect-square items-center justify-center rounded-md border-2 border-green-300 bg-green-500 p-2"
        >
            <CircleUserRound />
        </div>
    </div>
</div>
