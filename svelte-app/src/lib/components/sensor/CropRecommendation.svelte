<script>
    import { onMount } from "svelte";
    let someText = $state("Loading...");

    onMount(async () => {
        const resp = await fetch("/api/recommendations");
        const respJson = await resp.json();
        someText = respJson.data;
    });
</script>

<div class="w-full rounded-lg bg-gray-200 p-8">
    <h2 class="mb-2 text-center text-lg font-bold">Crop Recommendation</h2>
    <textarea
        readonly
        class="no-scrollbar h-64 w-full resize-none scroll-p-12 rounded-lg border-2 border-gray-800 p-4 text-lg"
        value={someText}
    ></textarea>
</div>
