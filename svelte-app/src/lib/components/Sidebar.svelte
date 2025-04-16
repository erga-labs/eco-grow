<script>
    import SidebarItem from "./SidebarItem.svelte";
    import { CircleUserRound } from "@lucide/svelte";

    const { sensorIds, currentSensor, onSensorClick } = $props();
</script>

<div class="fixed h-screen w-14 bg-red-300 px-2.5">
    <div class="flex h-full flex-col items-center justify-between py-4">
        <div class="flex flex-col gap-4">
            {#each sensorIds as id}
                <SidebarItem {id} isSelected={id === currentSensor} {onSensorClick} />
            {/each}
        </div>
        <div
            class="flex aspect-square items-center justify-center rounded-md border-2 border-green-300 bg-green-500 p-2"
        >
            <CircleUserRound />
        </div>
    </div>
</div>
