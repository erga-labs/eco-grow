<script>
    import { onMount } from "svelte";

    // Accept props from parent component
    const { currentCrop, currentValues } = $props();

    let recommendationText = $state("Loading...");
    let isLoading = $state(true);
    let error = $state(null);

    onMount(async () => {
        try {
            // Pass currentCrop and currentValues to the API
            const resp = await fetch("/api/recommendations", {
                method: "POST",
                headers: {
                    "Content-Type": "application/json",
                },
                body: JSON.stringify({
                    crop: currentCrop,
                    values: currentValues,
                }),
            });

            if (!resp.ok) {
                throw new Error(`API responded with status: ${resp.status}`);
            }

            const respJson = await resp.json();
            recommendationText = respJson.data;
        } catch (err) {
            console.error("Error fetching recommendations:", err);
            error = err.message || "Failed to fetch recommendations";
            recommendationText = "Error loading recommendations. Please try again.";
        } finally {
            isLoading = false;
        }
    });
</script>

<div class="w-full rounded-lg p-8" style="background-color: var(--color-background); color: var(--color-text);">
    <h2 class="mb-2 text-center text-lg font-bold" style="color: var(--color-primary);">Crop Recommendation</h2>

    {#if isLoading}
        <div
            class="flex h-64 w-full items-center justify-center rounded-lg border-2"
            style="border-color: var(--color-primary); background-color: white;"
        >
            <div class="flex flex-col items-center">
                <div
                    class="h-12 w-12 animate-spin rounded-full border-4"
                    style="border-color: var(--color-accent); border-top-color: var(--color-primary);"
                ></div>
                <p class="mt-3" style="color: var(--color-primary);">Loading recommendations...</p>
            </div>
        </div>
    {:else if error}
        <div
            class="flex h-64 w-full items-center justify-center rounded-lg border-2 p-4"
            style="border-color: var(--color-error); background-color: rgba(186, 24, 27, 0.1);"
        >
            <div class="text-center">
                <svg
                    class="mx-auto mb-2 h-12 w-12"
                    fill="none"
                    stroke="currentColor"
                    viewBox="0 0 24 24"
                    xmlns="http://www.w3.org/2000/svg"
                    style="color: var(--color-error);"
                >
                    <path
                        stroke-linecap="round"
                        stroke-linejoin="round"
                        stroke-width="2"
                        d="M12 8v4m0 4h.01M21 12a9 9 0 11-18 0 9 9 0 0118 0z"
                    ></path>
                </svg>
                <p style="color: var(--color-error);">{error}</p>
            </div>
        </div>
    {:else}
        <textarea
            readonly
            class="no-scrollbar h-64 w-full resize-none scroll-p-12 rounded-lg border-2 p-4 text-lg"
            style="border-color: var(--color-primary); background-color: white; color: var(--color-text);"
            value={recommendationText}
        ></textarea>
    {/if}

    <!-- Debug info - can be removed in production -->
    {#if currentCrop && currentValues && !isLoading}
        <div class="mt-2 text-xs opacity-60">
            <details>
                <summary class="cursor-pointer" style="color: var(--color-secondary);">Debug Info</summary>
                <div class="mt-1 rounded p-2" style="background-color: rgba(39, 98, 82, 0.1);">
                    <p>Current Crop: {currentCrop}</p>
                    <p>Current Values: {JSON.stringify(currentValues)}</p>
                </div>
            </details>
        </div>
    {/if}
</div>

<style>
    :global(:root) {
        --color-text: #040316;
        --color-primary: #276252;
        --color-background: #e5e5e5;
        --color-secondary: #6a9587;
        --color-accent: #abd3bb;
        --color-error: #ba181b;
    }

    .no-scrollbar::-webkit-scrollbar {
        display: none;
    }

    .no-scrollbar {
        -ms-overflow-style: none;
        scrollbar-width: none;
    }
</style>
