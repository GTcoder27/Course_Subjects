def graph_coloring(graph, colors, coloring, region_idx, regions):
    if region_idx == len(regions):
        return True
    
    region = regions[region_idx]
    for color in range(colors):
        if all(coloring.get(neighbor) != color for neighbor in graph[region]):
            coloring[region] = color
            if graph_coloring(graph, colors, coloring, region_idx + 1, regions):
                return True
            del coloring[region]
    return False

# Example usage
graph = {
    'A': ['B', 'D'],
    'B': ['A', 'C'], 
    'C': ['B', 'D'],
    'D': ['A', 'C']
}

regions = list(graph.keys())
coloring = {}

if graph_coloring(graph, 3, coloring, 0, regions):
    print("Solution found:")
    for region, color in coloring.items():
        print(f"{region}: Color {color}")
else:
    print("No solution")