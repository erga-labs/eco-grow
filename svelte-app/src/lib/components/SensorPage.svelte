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

<div class="flex h-full w-full flex-col gap-2 overflow-auto rounded-lg bg-red-200 px-8 py-6">
    <SensorInfo sensorId={sensor} isOnline={false} />

    <div class="flex gap-4 md:flex-col md:gap-8 lg:flex-row">
        <div class="w-1/2 rounded-lg md:w-full">
            <GraphComponent />
        </div>
        <div class="flex w-1/2 flex-col gap-8 md:w-full">
            <PlantInformation {currentCrop} {currentValues} />
            <CropRecommendation />
        </div>
    </div>
</div>
