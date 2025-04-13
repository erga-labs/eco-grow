<script>
    import GraphComponent from "$lib/components/sensor/GraphComponent.svelte";
    import PlantInformation from "$lib/components/sensor/PlantInformation.svelte";
    import CropRecommendation from "$lib/components/sensor/CropRecommendation.svelte";
    export let selectedSensor = "";
</script>

<!-- Outer container -->
<div class="min-h-full w-full overflow-auto rounded-lg bg-red-400 px-8">
    <p class="px-2 pb-2 text-lg font-semibold text-white">
        Selected Sensor: {selectedSensor}
    </p>

    <!-- Graph wrapper: 1/2 screen on md+, full screen on small -->
    <div class="flex gap-4 md:flex-col md:gap-8 lg:flex-row">
        <div
            class="h-full w-1/2 flex-3/4 rounded-l bg-amber-50
                    px-3 md:h-1/2 md:w-full"
        >
            <GraphComponent />
        </div>
        <div class="flex h-full w-1/2 flex-col gap-8 md:w-full">
            <PlantInformation />
            <CropRecommendation />
        </div>
    </div>
</div>
