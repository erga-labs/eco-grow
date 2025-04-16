<script>
    import SensorPage from "$lib/components/SensorPage.svelte";
    import Sidebar from "$lib/components/Sidebar.svelte";
    import { getSensors } from "$lib/functions";

    const sensorIds = getSensors();
    let currentSensor = $state(sensorIds[0]);

    const onSensorClick = (sensorId) => (currentSensor = sensorId);
</script>

<div class="flex h-screen">
    <Sidebar {sensorIds} {currentSensor} {onSensorClick} />
    <div class="h-full w-full py-2 pr-2 pl-16">
        <SensorPage sensor={currentSensor} />
    </div>
</div>
