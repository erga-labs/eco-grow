<script>
    import { Cpu } from "@lucide/svelte";

    let { sensorId, isOnline } = $props();
</script>

<div class={`${isOnline ? "bg-[#ABD3BB]" : "bg-[#BA181B]"} flex h-12 items-center justify-center gap-4 rounded-md p-2`}>
    <Cpu />
    <p class={`font-bold ${isOnline ? "text-[#276252]" : "text-white"} text-xl`}>
        Sensor ID: {sensorId}
    </p>
</div>
