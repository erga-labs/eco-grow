<script>

  import SidebarItem from "./sidebarItem.svelte";
  import { CircleUserRound } from '@lucide/svelte';

  let { ids, onCpuCLick } = $props();
//   console.log(onCpuCLick);

  ids = ["123", "213", "312", "412", "512", "612"];

</script>


<div class="w-auto px-2.5 h-full bg-red-500">
    <div class="flex flex-col justify-between h-full py-4 items-center">
        <div class="flex flex-col gap-4">

{#each ids as id}
            <SidebarItem onCpuCLick={() => onCpuCLick(id)} />
{/each}

        </div>
        <div class="aspect-square bg-green-500 p-2 rounded-md border-2 border-green-300 flex justify-center items-center">
            <CircleUserRound />
        </div>
    </div>
</div>

