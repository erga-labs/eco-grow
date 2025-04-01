<script>
	import '../app.css';
	
	let { children } = $props();
</script>

<svelte:head>
    <title>Seed Sync</title>
</svelte:head>
{@render children()}
