<script>
    import { Cpu } from "@lucide/svelte";

    let { sensorId, isOnline } = $props();
</script>

<div class={`${isOnline ? "bg-green-300" : "bg-red-300"} flex h-12 items-center justify-center gap-4 rounded-md p-2`}>
    <Cpu />
    <p class={`font-bold ${isOnline ? "text-green-800" : "text-red-800"} text-xl`}>
        Sensor ID: {sensorId}
    </p>
</div>
