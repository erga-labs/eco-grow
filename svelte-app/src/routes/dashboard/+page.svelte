<!-- <script>
  import SensorPage from "$lib/components/sensorPage.svelte";
  import Sidebar from "$lib/components/sidebar.svelte";

  const x = (id) => console.log(id);
</script>

<div class="h-full flex ">
    <Sidebar onCpuCLick={x} />
    <div class="p-2 h-full w-full">
      <SensorPage />
    </div>
  </div>
 -->

<script>
  import SensorPage from "$lib/components/sensorPage.svelte";
  import Sidebar from "$lib/components/sidebar.svelte";

  
  let ids = ["123", "213", "312", "412", "512"];
  let selectedSensor = ids[0];

  const handleCpuClick = (id) => {
    selectedSensor = id;
    console.log("Selected Sensor:", id);
  };
</script>

<div class="h-full flex">
  <Sidebar {ids} onCpuClick={handleCpuClick} />

  <div class="p-2 h-full w-full">
    <SensorPage {selectedSensor} />
  </div>
</div>
  