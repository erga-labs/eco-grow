<script>
    import { onMount } from "svelte";

    const logs = `2025-04-22 22:00:00 INFO Device started successfully. Device ID: IoT-Device-001
2025-04-22 22:05:15 DEBUG Sensor reading: Temperature=24.5°C, Humidity=40%
2025-04-22 22:10:30 INFO Data packet sent to server. Packet ID: 12345
2025-04-22 22:15:45 WARN Battery level low: 15%
2025-04-22 22:20:00 ERROR Sensor timeout detected. Attempting to reset sensor.
2025-04-22 22:21:10 INFO Sensor reset successful.
2025-04-22 22:25:00 DEBUG Sensor reading: Temperature=24.7°C, Humidity=39%
2025-04-22 22:30:00 INFO Firmware update check: No updates available.
2025-04-22 22:35:00 INFO Data packet sent to server. Packet ID: 12346
2025-04-22 22:40:00 INFO Device entering sleep mode to conserve power.
2025-04-22 22:45:00 INFO Device woke up from sleep mode.
2025-04-22 22:50:00 DEBUG Sensor reading: Temperature=24.6°C, Humidity=38%
2025-04-22 22:55:00 INFO Data packet sent to server. Packet ID: 12347
2025-04-22 23:00:00 INFO Device heartbeat signal sent.
`;

    let showLogs = $state(false);
    onMount(() => {
        const isMobile = () => {
            return /Android|webOS|iPhone|iPad|iPod|BlackBerry|IEMobile|Opera Mini/i.test(navigator.userAgent);
        };
        showLogs = !isMobile();
    });
</script>

<div class="w-full rounded-lg bg-gray-200 p-8">
    <h2 class="mb-2 text-center text-lg font-bold">Logs</h2>
    {#if showLogs}
        <textarea
            readonly
            class="no-scrollbar h-64 w-full resize-none scroll-p-12 rounded-lg border-2 border-gray-800 p-4 text-sm"
            value={logs}
        ></textarea>
    {:else}
        <button onclick={() => (showLogs = true)} class="w-full rounded bg-green-200 px-4 py-2 text-center shadow"
            >Show Logs</button
        >
    {/if}
</div>
