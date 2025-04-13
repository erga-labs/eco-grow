<script>
    import { Cpu } from "@lucide/svelte";
    import { createEventDispatcher } from "svelte";

    const dispatch = createEventDispatcher();

    // Add isSelected prop to track selection state
    // export let id = null;
    export let isSelected = false;
</script>

<button
    class="aspect-square w-full rounded-md bg-green-500 p-2
      {isSelected ? 'border-2 border-blue-800' : 'border-2 border-green-300'} 
      transition-all duration-200"
    on:click={() => dispatch("click")}
>
    <Cpu />
</button>
