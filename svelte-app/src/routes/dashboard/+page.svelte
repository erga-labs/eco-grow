<script>
    import SensorPage from "$lib/components/SensorPage.svelte";
    import Sidebar from "$lib/components/Sidebar.svelte";

    let ids = ["123", "213", "312", "412", "512"];
    let selectedSensor = ids[0];

    const handleCpuClick = (id) => {
        selectedSensor = id;
        console.log("Selected Sensor:", id);
    };
</script>

<div class="flex h-full">
    <Sidebar {ids} onCpuClick={handleCpuClick} />

    <div class="h-full w-full p-2">
        <SensorPage {selectedSensor} />
    </div>
</div>
