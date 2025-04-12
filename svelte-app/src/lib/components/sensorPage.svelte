<script>
    import GraphComponent from '$lib/components/sensor/graphComponent.svelte';

    export let selectedSensor = '';
</script>
  
<!-- Outer container -->
<div class="w-full min-h-full bg-red-400 p-2 overflow-auto rounded-lg">
    <p class="text-white text-lg font-semibold px-2 pb-2">
        Selected Sensor: {selectedSensor}
    </p>

    <!-- Graph wrapper: 1/2 screen on md+, full screen on small -->
    <div class="w-full h-full bg-amber-50 px-3 
                md:w-1/2 md:h-1/2 md:my-12 rounded-l">
        <GraphComponent />
    </div>
</div>

