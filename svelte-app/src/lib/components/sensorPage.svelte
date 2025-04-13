<script>
    import GraphComponent from '$lib/components/sensor/graphComponent.svelte';
    import PlantInformation from '$lib/components/sensor/PlantInformation.svelte';
    export let selectedSensor = '';
</script>
  
<!-- Outer container -->
<div class="w-full min-h-full bg-red-400 p-2 overflow-auto rounded-lg">
    <p class="text-white text-lg font-semibold px-2 pb-2">
        Selected Sensor: {selectedSensor}
    </p>

    <!-- Graph wrapper: 1/2 screen on md+, full screen on small -->
    <div class="flex lg:flex-row gap-4 md:gap-8 md:flex-col">
    
        <div class="w-full h-full bg-amber-50 px-3 
                    md:w-1/2 md:h-1/2 rounded-l">
            <GraphComponent />
        </div>
    
        <div class="w-full md:w-1/2 md:h-1/2 h-full">
            <PlantInformation />
        </div>
        
    </div>
</div>

