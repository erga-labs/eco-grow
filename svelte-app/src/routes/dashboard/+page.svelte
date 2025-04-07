<script>
  import SensorPage from "$lib/components/sensorPage.svelte";
  import Sidebar from "$lib/components/sidebar.svelte";

  const x = (id) => console.log(id);
</script>

<div class="h-full flex">
    <Sidebar onCpuCLick={x} />
    <SensorPage />
  </div>
