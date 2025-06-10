def is_safe(region, color, coloring, graph):
    for neighbor in graph[region]:
        if neighbor in coloring and coloring[neighbor] == color:
            return False
    return True

def color_map(graph, colors, coloring={}, region=0):
    regions = list(graph.keys())
    if region == len(regions):
        return coloring
    
    for color in colors:
        if is_safe(regions[region], color, coloring, graph):
            coloring[regions[region]] = color
            result = color_map(graph, colors, coloring, region + 1)
            if result:
                return result
            del coloring[regions[region]]
    
    return None

# User-defined input
graph = {}
n = int(input("Enter number of regions: "))
for _ in range(n):
    region = input("Enter region name: ")
    neighbors = input("Enter neighboring regions (comma-separated): ").split(',')
    graph[region] = [neighbor.strip() for neighbor in neighbors if neighbor.strip()]

colors = input("Enter available colors (comma-separated): ").split(',')
colors = [color.strip() for color in colors if color.strip()]

solution = color_map(graph, colors)
print("Coloring Solution:", solution)
