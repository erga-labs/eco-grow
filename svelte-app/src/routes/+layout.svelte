<script>
	import '../app.css';
	
	let { children } = $props();
</script>

<svelte:head>
    <title>Seed Sync</title>
</svelte:head>
<meta name="viewport" content="width=device-width, initial-scale=1.0">
{@render children()}
