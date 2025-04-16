<script>
    import { Cpu } from "@lucide/svelte";
    import { createEventDispatcher } from "svelte";

    const { id, onSensorClick, isSelected } = $props();
</script>

<button
    class="flex aspect-square w-full items-center justify-center rounded-md bg-green-500 p-2
      {isSelected ? 'border-4 border-indigo-600' : 'border-4 border-green-300'} 
      transition-all duration-200"
    onclick={() => onSensorClick(id)}
>
    <Cpu />
</button>
