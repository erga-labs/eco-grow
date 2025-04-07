<script>
    import { Cpu } from '@lucide/svelte';
    const { onCpuCLick } = $props();
</script>
    

<button class="aspect-square w-full bg-green-500 p-2 rounded-md border-2 border-green-300">
    <Cpu onclick={onCpuCLick}/> 
</button>