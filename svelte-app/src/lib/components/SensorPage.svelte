<script>
    import GraphComponent from "$lib/components/sensor/GraphComponent.svelte";
    import PlantInformation from "$lib/components/sensor/PlantInformation.svelte";
    import CropRecommendation from "$lib/components/sensor/CropRecommendation.svelte";
    import SensorInfo from "./sensor/SensorInfo.svelte";
    import { getDataForSensor } from "$lib/functions";

    const { sensor } = $props();

    // TODO: use this instead
    const { currentCrop, currentValues } = getDataForSensor(sensor);
</script>

<div class="flex h-full w-full flex-col gap-2 overflow-auto rounded-lg bg-red-200 px-4 py-4 sm:px-6 md:px-8 md:py-6">
    <SensorInfo sensorId={sensor} isOnline={false} />

    <div class="flex flex-col gap-4 lg:flex-row lg:gap-8">
        <div class="w-full lg:w-1/2 rounded-lg">
            <GraphComponent />
        </div>
        <div class="flex w-full flex-col gap-8 lg:w-1/2">
            <PlantInformation {currentCrop} {currentValues} />
            <CropRecommendation />
        </div>
    </div>
</div>
