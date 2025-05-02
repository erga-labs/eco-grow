<script>
    import { classifyImage } from "$lib/functions/classify";
    
    let result = null;
    let loading = false;
    let error = null;
    let selectedFile = null;
    let previewUrl = null;

    const handleFileUpload = async (event) => {
        const file = event.target.files[0];
        if (!file) return;
        
        // Reset states
        loading = true;
        error = null;
        result = null;
        selectedFile = file;
        
        // Create preview
        previewUrl = URL.createObjectURL(file);
        
        try {
            const reader = new FileReader();
            
            reader.onload = async () => {
                try {
                    // Extract base64 string properly
                    const base64String = reader.result.split(",")[1];
                    
                    // Call the classification function
                    result = await classifyImage(base64String);
                } catch (err) {
                    console.error("Error classifying image:", err);
                    error = err.message || "Failed to classify image";
                } finally {
                    loading = false;
                }
            };
            
            reader.onerror = (err) => {
                console.error("Error reading file:", err);
                error = "Failed to read the image file";
                loading = false;
                previewUrl = null;
            };
            
            reader.readAsDataURL(file);
        } catch (err) {
            console.error("Error in file handling:", err);
            error = err.message || "An unexpected error occurred";
            loading = false;
            previewUrl = null;
        }
    };

    // Clean up object URL on component unmount
    import { onDestroy } from 'svelte';
    onDestroy(() => {
        if (previewUrl) {
            URL.revokeObjectURL(previewUrl);
        }
    });
</script>

<style>
    :global(:root) {
        --color-text: #040316;
        --color-primary: #276252;
        --color-background: #E5E5E5;
        --color-secondary: #6A9587;
        --color-accent: #ABD3BB;
        --color-error: #BA181B;
    }
</style>

<div class="w-full mx-auto rounded-lg p-6 shadow-lg" style="background-color: var(--color-background); color: var(--color-text);">
    <h2 class="text-2xl font-bold text-center mb-6" style="color: var(--color-primary);">Plant Health Classifier</h2>
    
    <!-- File Upload Area -->
    <div class="mb-6">
        <!-- <label for="image-upload" class="block text-sm font-medium mb-2">Upload a plant image for analysis</label> -->
        <div class="relative">
            <input 
                id="image-upload"
                type="file" 
                class="hidden"
                accept="image/*" 
                on:change={handleFileUpload} 
            />
            <label 
                for="image-upload" 
                class="flex items-center justify-center w-full px-4 py-3 rounded-lg cursor-pointer border-2 border-dashed transition-colors"
                style="border-color: var(--color-secondary); background-color: white;"
            >
                <div class="flex flex-col items-center justify-center text-center">
                    <svg class="w-8 h-8" fill="none" stroke="currentColor" viewBox="0 0 24 24" xmlns="http://www.w3.org/2000/svg" style="color: var(--color-primary);">
                        <path stroke-linecap="round" stroke-linejoin="round" stroke-width="2" d="M4 16l4.586-4.586a2 2 0 012.828 0L16 16m-2-2l1.586-1.586a2 2 0 012.828 0L20 14m-6-6h.01M6 20h12a2 2 0 002-2V6a2 2 0 00-2-2H6a2 2 0 00-2 2v12a2 2 0 002 2z"></path>
                    </svg>
                    <p class="mt-2 text-sm">
                        {#if selectedFile}
                            Selected: {selectedFile.name}
                        {:else}
                            Click to select an image
                        {/if}
                    </p>
                </div>
            </label>
        </div>
    </div>
    
    <!-- Preview and Results Area -->
    {#if loading || previewUrl || error || result}
        <div class="rounded-lg p-5 shadow-md" style="background-color: white;">
            <!-- Image Preview -->
            {#if previewUrl}
                <div class="mb-5 flex justify-center">
                    <img src={previewUrl} alt="Preview" class="max-h-64 rounded-lg object-contain" />
                </div>
            {/if}
            
            <!-- Loading Indicator -->
            {#if loading}
                <div class="flex flex-col items-center justify-center py-4">
                    <div class="w-12 h-12 border-4 rounded-full animate-spin" style="border-color: var(--color-accent); border-top-color: var(--color-primary);"></div>
                    <p class="mt-3" style="color: var(--color-primary);"/>
                    <script>
                        import { classifyImage } from "$lib/functions/classify";
                        
                        let result = null;
                        let loading = false;
                        let error = null;
                        let selectedFile = null;
                        let previewUrl = null;
                    
                        const handleFileUpload = async (event) => {
                            const file = event.target.files[0];
                            if (!file) return;
                            
                            // Reset states
                            loading = true;
                            error = null;
                            result = null;
                            selectedFile = file;
                            
                            // Create preview
                            previewUrl = URL.createObjectURL(file);
                            
                            try {
                                const reader = new FileReader();
                                
                                reader.onload = async () => {
                                    try {
                                        // Extract base64 string properly
                                        const base64String = reader.result.split(",")[1];
                                        
                                        // Call the classification function
                                        result = await classifyImage(base64String);
                                    } catch (err) {
                                        console.error("Error classifying image:", err);
                                        error = err.message || "Failed to classify image";
                                    } finally {
                                        loading = false;
                                    }
                                };
                                
                                reader.onerror = (err) => {
                                    console.error("Error reading file:", err);
                                    error = "Failed to read the image file";
                                    loading = false;
                                    previewUrl = null;
                                };
                                
                                reader.readAsDataURL(file);
                            } catch (err) {
                                console.error("Error in file handling:", err);
                                error = err.message || "An unexpected error occurred";
                                loading = false;
                                previewUrl = null;
                            }
                        };
                    
                        // Clean up object URL on component unmount
                        import { onDestroy } from 'svelte';
                        onDestroy(() => {
                            if (previewUrl) {
                                URL.revokeObjectURL(previewUrl);
                            }
                        });
                    </script>
                    
                    <div class="max-w-xl w-full mx-auto rounded-xl bg-gradient-to-br from-blue-50 to-purple-50 p-6 shadow-lg border border-purple-100">
                        <h2 class="text-2xl font-bold text-center mb-6 text-purple-800">Plant Health Classifier</h2>
                        
                        <!-- File Upload Area -->
                        <div class="mb-6">
                            <!-- <label for="image-upload" class="block text-sm font-medium text-gray-700 mb-2 text-center">Upload a plant image for analysis.</label> -->
                            <div class="relative">
                                <input 
                                    id="image-upload"
                                    type="file" 
                                    class="hidden"
                                    accept="image/*" 
                                    on:change={handleFileUpload} 
                                />
                                <label 
                                    for="image-upload" 
                                    class="flex items-center justify-center w-full px-4 py-3 bg-white rounded-lg cursor-pointer border-2 border-dashed border-purple-300 hover:bg-purple-50 transition-colors"
                                >
                                    <div class="flex flex-col items-center justify-center text-center">
                                        <svg class="w-8 h-8 text-purple-500" fill="none" stroke="currentColor" viewBox="0 0 24 24" xmlns="http://www.w3.org/2000/svg">
                                            <path stroke-linecap="round" stroke-linejoin="round" stroke-width="2" d="M4 16l4.586-4.586a2 2 0 012.828 0L16 16m-2-2l1.586-1.586a2 2 0 012.828 0L20 14m-6-6h.01M6 20h12a2 2 0 002-2V6a2 2 0 00-2-2H6a2 2 0 00-2 2v12a2 2 0 002 2z"></path>
                                        </svg>
                                        <p class="mt-2 text-sm text-gray-600">
                                            {#if selectedFile}
                                                Selected: {selectedFile.name}
                                            {:else}
                                                Click to select an image
                                            {/if}
                                        </p>
                                    </div>
                                </label>
                            </div>
                        </div>
                        
                        <!-- Preview and Results Area -->
                        {#if loading || previewUrl || error || result}
                            <div class="bg-white rounded-lg p-5 shadow-md">
                                <!-- Image Preview -->
                                {#if previewUrl}
                                    <div class="mb-5 flex justify-center">
                                        <img src={previewUrl} alt="Preview" class="max-h-64 rounded-lg object-contain" />
                                    </div>
                                {/if}
                                
                                <!-- Loading Indicator -->
                                {#if loading}
                                    <div class="flex flex-col items-center justify-center py-4">
                                        <div class="w-12 h-12 border-4 border-purple-200 border-t-purple-600 rounded-full animate-spin"></div>
                                        <p class="mt-3 text-purple-700">Analyzing image...</p>
                                    </div>
                                <!-- Error Message -->
                                {:else if error}
                                    <div class="bg-red-50 border-l-4 border-red-500 p-4 rounded">
                                        <div class="flex items-center">
                                            <svg class="w-6 h-6 text-red-500 mr-2" fill="none" stroke="currentColor" viewBox="0 0 24 24" xmlns="http://www.w3.org/2000/svg">
                                                <path stroke-linecap="round" stroke-linejoin="round" stroke-width="2" d="M12 8v4m0 4h.01M21 12a9 9 0 11-18 0 9 9 0 0118 0z"></path>
                                            </svg>
                                            <p class="text-red-700">{error}</p>
                                        </div>
                                    </div>
                                <!-- Results -->
                                {:else if result}
                                    <div class="mb-2">
                                        <h3 class="text-xl font-bold text-center text-purple-800 mb-4">Classification Result</h3>
                                        <div class="bg-gray-50 p-4 rounded-lg border border-gray-200">
                                            {#if result.healthy === true}
                                                <div class="flex items-center justify-center bg-green-100 p-4 rounded-lg">
                                                    <svg class="w-8 h-8 text-green-600 mr-3" fill="none" stroke="currentColor" viewBox="0 0 24 24" xmlns="http://www.w3.org/2000/svg">
                                                        <path stroke-linecap="round" stroke-linejoin="round" stroke-width="2" d="M9 12l2 2 4-4m6 2a9 9 0 11-18 0 9 9 0 0118 0z"></path>
                                                    </svg>
                                                    <span class="text-lg font-semibold text-green-800">Healthy Plant</span>
                                                </div>
                                            {:else}
                                                <div class="flex items-center justify-center bg-red-100 p-4 rounded-lg">
                                                    <svg class="w-8 h-8 text-red-600 mr-3" fill="none" stroke="currentColor" viewBox="0 0 24 24" xmlns="http://www.w3.org/2000/svg">
                                                        <path stroke-line></path>
                                                        <script>
                                                            import { classifyImage } from "$lib/functions/classify";
                                                            
                                                            let result = null;
                                                            let loading = false;
                                                            let error = null;
                                                            let selectedFile = null;
                                                            let previewUrl = null;
                                                        
                                                            const handleFileUpload = async (event) => {
                                                                const file = event.target.files[0];
                                                                if (!file) return;
                                                                
                                                                // Reset states
                                                                loading = true;
                                                                error = null;
                                                                result = null;
                                                                selectedFile = file;
                                                                
                                                                // Create preview
                                                                previewUrl = URL.createObjectURL(file);
                                                                
                                                                try {
                                                                    const reader = new FileReader();
                                                                    
                                                                    reader.onload = async () => {
                                                                        try {
                                                                            // Extract base64 string properly
                                                                            const base64String = reader.result.split(",")[1];
                                                                            
                                                                            // Call the classification function
                                                                            result = await classifyImage(base64String);
                                                                        } catch (err) {
                                                                            console.error("Error classifying image:", err);
                                                                            error = err.message || "Failed to classify image";
                                                                        } finally {
                                                                            loading = false;
                                                                        }
                                                                    };
                                                                    
                                                                    reader.onerror = (err) => {
                                                                        console.error("Error reading file:", err);
                                                                        error = "Failed to read the image file";
                                                                        loading = false;
                                                                        previewUrl = null;
                                                                    };
                                                                    
                                                                    reader.readAsDataURL(file);
                                                                } catch (err) {
                                                                    console.error("Error in file handling:", err);
                                                                    error = err.message || "An unexpected error occurred";
                                                                    loading = false;
                                                                    previewUrl = null;
                                                                }
                                                            };
                                                        
                                                            // Clean up object URL on component unmount
                                                            import { onDestroy } from 'svelte';
                                                            onDestroy(() => {
                                                                if (previewUrl) {
                                                                    URL.revokeObjectURL(previewUrl);
                                                                }
                                                            });
                                                        </script>
                                                        
                                                        <div class="max-w-xl w-full mx-auto rounded-xl bg-gradient-to-br from-blue-50 to-purple-50 p-6 shadow-lg border border-purple-100">
                                                            <h2 class="text-2xl font-bold text-center mb-6 text-purple-800">Plant Health Classifier</h2>
                                                            
                                                            <!-- File Upload Area -->
                                                            <div class="mb-6">
                                                                <!-- <label for="image-upload" class="block text-sm font-medium text-gray-700 mb-2 text-center">Upload a plant image for analysis.</label> -->
                                                                <div class="relative">
                                                                    <input 
                                                                        id="image-upload"
                                                                        type="file" 
                                                                        class="hidden"
                                                                        accept="image/*" 
                                                                        on:change={handleFileUpload} 
                                                                    />
                                                                    <label 
                                                                        for="image-upload" 
                                                                        class="flex items-center justify-center w-full px-4 py-3 bg-white rounded-lg cursor-pointer border-2 border-dashed border-purple-300 hover:bg-purple-50 transition-colors"
                                                                    >
                                                                        <div class="flex flex-col items-center justify-center text-center">
                                                                            <svg class="w-8 h-8 text-purple-500" fill="none" stroke="currentColor" viewBox="0 0 24 24" xmlns="http://www.w3.org/2000/svg">
                                                                                <path stroke-linecap="round" stroke-linejoin="round" stroke-width="2" d="M4 16l4.586-4.586a2 2 0 012.828 0L16 16m-2-2l1.586-1.586a2 2 0 012.828 0L20 14m-6-6h.01M6 20h12a2 2 0 002-2V6a2 2 0 00-2-2H6a2 2 0 00-2 2v12a2 2 0 002 2z"></path>
                                                                            </svg>
                                                                            <p class="mt-2 text-sm text-gray-600">
                                                                                {#if selectedFile}
                                                                                    Selected: {selectedFile.name}
                                                                                {:else}
                                                                                    Click to select an image
                                                                                {/if}
                                                                            </p>
                                                                        </div>
                                                                    </label>
                                                                </div>
                                                            </div>
                                                            
                                                            <!-- Preview and Results Area -->
                                                            {#if loading || previewUrl || error || result}
                                                                <div class="bg-white rounded-lg p-5 shadow-md">
                                                                    <!-- Image Preview -->
                                                                    {#if previewUrl}
                                                                        <div class="mb-5 flex justify-center">
                                                                            <img src={previewUrl} alt="Preview" class="max-h-64 rounded-lg object-contain" />
                                                                        </div>
                                                                    {/if}
                                                                    
                                                                    <!-- Loading Indicator -->
                                                                    {#if loading}
                                                                        <div class="flex flex-col items-center justify-center py-4">
                                                                            <div class="w-12 h-12 border-4 border-purple-200 border-t-purple-600 rounded-full animate-spin"></div>
                                                                            <p class="mt-3 text-purple-700">Analyzing image...</p>
                                                                        </div>
                                                                    <!-- Error Message -->
                                                                    {:else if error}
                                                                        <div class="bg-red-50 border-l-4 border-red-500 p-4 rounded">
                                                                            <div class="flex items-center">
                                                                                <svg class="w-6 h-6 text-red-500 mr-2" fill="none" stroke="currentColor" viewBox="0 0 24 24" xmlns="http://www.w3.org/2000/svg">
                                                                                    <path stroke-linecap="round" stroke-linejoin="round" stroke-width="2" d="M12 8v4m0 4h.01M21 12a9 9 0 11-18 0 9 9 0 0118 0z"></path>
                                                                                </svg>
                                                                                <p class="text-red-700">{error}</p>
                                                                            </div>
                                                                        </div>
                                                                    <!-- Results -->
                                                                    {:else if result}
                                                                        <div class="mb-2">
                                                                            <h3 class="text-xl font-bold text-center text-purple-800 mb-4">Classification Result</h3>
                                                                            <div class="bg-gray-50 p-4 rounded-lg border border-gray-200">
                                                                                {#if result.healthy === true}
                                                                                    <div class="flex items-center justify-center bg-green-100 p-4 rounded-lg">
                                                                                        <svg class="w-8 h-8 text-green-600 mr-3" fill="none" stroke="currentColor" viewBox="0 0 24 24" xmlns="http://www.w3.org/2000/svg">
                                                                                            <path stroke-linecap="round" stroke-linejoin="round" stroke-width="2" d="M9 12l2 2 4-4m6 2a9 9 0 11-18 0 9 9 0 0118 0z"></path>
                                                                                        </svg>
                                                                                        <span class="text-lg font-semibold text-green-800">Healthy Plant</span>
                                                                                    </div>
                                                                                {:else}
                                                                                    <div class="flex items-center justify-center bg-red-100 p-4 rounded-lg">
                                                                                        <svg class="w-8 h-8 text-red-600 mr-3" fill="none" stroke="currentColor" viewBox="0 0 24 24" xmlns="http://www.w3.org/2000/svg">
                                                                                            <path stroke-linecap="round" stroke-linejoin="round" stroke-width="2" d="M10 14l2-2m0 0l2-2m-2 2l-2-2m2 2l2 2m7-2a9 9 0 11-18 0 9 9 0 0118 0z"></path>
                                                                                        </svg>
                                                                                        <span class="text-lg font-semibold text-red-800">Unhealthy Plant</span>
                                                                                    </div>
                                                                                {/if}
                                                                            </div>
                                                                        </div>
                                                                        
                                                                        <!-- Raw JSON (optional, can be removed) -->
                                                                        <div class="mt-4">
                                                                            <details class="text-sm">
                                                                                <summary class="text-purple-700 cursor-pointer hover:text-purple-900">View raw response</summary>
                                                                                <pre class="mt-2 bg-gray-100 p-3 rounded overflow-auto text-xs">{JSON.stringify(result, null, 2)}</pre>
                                                                            </details>
                                                                        </div>
                                                                    {/if}
                                                                </div>
                                                            {/if}
                                                            
                                                            <!-- Footer -->
                                                            <div class="mt-6 text-center text-xs text-gray-500">
                                                                <p>Upload plant images to check for signs of disease or stress</p>
                                                            </div>
                    
                                                    </svg>
                                                    <span class="text-lg font-semibold text-red-800">Unhealthy Plant</span>
                                                </div>
                                            {/if}
                                        </div>
                                    </div>
                                    
                                    <!-- Raw JSON (optional, can be removed) -->
                                    <div class="mt-4">
                                        <details class="text-sm">
                                            <summary class="text-purple-700 cursor-pointer hover:text-purple-900">View raw response</summary>
                                            <pre class="mt-2 bg-gray-100 p-3 rounded overflow-auto text-xs">{JSON.stringify(result, null, 2)}</pre>
                                        </details>
                                    </div>
                                {/if}
                            </div>
                        {/if}
                        
                        <!-- Footer -->
                        <div class="mt-6 text-center text-xs text-gray-500">
                            <p>Upload plant images to check for signs of disease or stress</p>
                        </div>
                    </div>Analyzing image...
                </div>
            <!-- Error Message -->
            {:else if error}
                <div class="p-4 rounded" style="background-color: rgba(186, 24, 27, 0.1); border-left: 4px solid var(--color-error);">
                    <div class="flex items-center">
                        <svg class="w-6 h-6 mr-2" fill="none" stroke="currentColor" viewBox="0 0 24 24" xmlns="http://www.w3.org/2000/svg" style="color: var(--color-error);">
                            <path stroke-linecap="round" stroke-linejoin="round" stroke-width="2" d="M12 8v4m0 4h.01M21 12a9 9 0 11-18 0 9 9 0 0118 0z"></path>
                        </svg>
                        <p style="color: var(--color-error);">{error}</p>
                    </div>
                </div>
            <!-- Results -->
            {:else if result}
                <div class="mb-2">
                    <h3 class="text-xl font-bold text-center mb-4" style="color: var(--color-primary);">Classification Result</h3>
                    <div class="p-4 rounded-lg border" style="border-color: var(--color-accent); background-color: rgba(171, 211, 187, 0.1);">
                        {#if result.healthy === true}
                            <div class="flex items-center justify-center p-4 rounded-lg" style="background-color: rgba(39, 98, 82, 0.1);">
                                <svg class="w-8 h-8 mr-3" fill="none" stroke="currentColor" viewBox="0 0 24 24" xmlns="http://www.w3.org/2000/svg" style="color: var(--color-primary);">
                                    <path stroke-linecap="round" stroke-linejoin="round" stroke-width="2" d="M9 12l2 2 4-4m6 2a9 9 0 11-18 0 9 9 0 0118 0z"></path>
                                </svg>
                                <span class="text-lg font-semibold" style="color: var(--color-primary);">Healthy Plant</span>
                            </div>
                        {:else}
                            <div class="flex items-center justify-center p-4 rounded-lg" style="background-color: rgba(186, 24, 27, 0.1);">
                                <svg class="w-8 h-8 mr-3" fill="none" stroke="currentColor" viewBox="0 0 24 24" xmlns="http://www.w3.org/2000/svg" style="color: var(--color-error);">
                                    <path stroke-linecap="round" stroke-linejoin="round" stroke-width="2" d="M10 14l2-2m0 0l2-2m-2 2l-2-2m2 2l2 2m7-2a9 9 0 11-18 0 9 9 0 0118 0z"></path>
                                </svg>
                                <span class="text-lg font-semibold" style="color: var(--color-error);">Unhealthy Plant</span>
                            </div>
                        {/if}
                    </div>
                </div>
                
                <!-- Raw JSON -->
                <div class="mt-4">
                    <details class="text-sm">
                        <summary class="cursor-pointer hover:underline" style="color: var(--color-secondary);">View raw response</summary>
                        <pre class="mt-2 p-3 rounded overflow-auto text-xs" style="background-color: var(--color-background);">{JSON.stringify(result, null, 2)}</pre>
                    </details>
                </div>
            {/if}
        </div>
    {/if}
    
    <!-- Footer -->
    <div class="mt-6 text-center text-xs opacity-70">
        <p>Upload plant images to check for signs of disease or stress</p>
    </div>
</div>