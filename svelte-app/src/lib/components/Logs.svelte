<script>
    import { onMount } from "svelte";

    let logs = $state("");

    let showLogs = $state(false);
    onMount(async () => {
        const isMobile = () => {
            return /Android|webOS|iPhone|iPad|iPod|BlackBerry|IEMobile|Opera Mini/i.test(navigator.userAgent);
        };
        showLogs = !isMobile();

        const resp = await fetch("/api/logs");
        const respJson = await resp.json();
        logs = respJson.data;
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
