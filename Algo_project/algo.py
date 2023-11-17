import matplotlib.pyplot as plt

class CoordinateSystem:
    def __init__(self):
        self.coordinates = []
        self.fig, self.ax = plt.subplots()
        self.ax.set(title='Click on the Coordinate System to Enter Points',
                    xlabel='X-axis', ylabel='Y-axis')
        self.cid = self.fig.canvas.mpl_connect('button_press_event', self.onclick)

    def onclick(self, event):
        if event.inaxes == self.ax:
            x, y = event.xdata, event.ydata
            self.coordinates.append((x, y))
            self.ax.plot(x, y, 'ro')  # Plot the clicked point
            plt.draw()

            if len(self.coordinates) == 2:
                # Draw a line between the first and second pairs of points
                self.ax.plot([self.coordinates[0][0], self.coordinates[1][0]],
                             [self.coordinates[0][1], self.coordinates[1][1]], 'b-')
                plt.draw()

                # Print the coordinates
                print("Entered Coordinates:")
                for i, coord in enumerate(self.coordinates):
                    print(f"Point {i + 1}: ({coord[0]}, {coord[1]})")

                # Disconnect the click event after two points are entered
                self.fig.canvas.mpl_disconnect(self.cid)

    def show_plot(self):
        plt.show()

# Create an instance of the CoordinateSystem class
coordinate_system = CoordinateSystem()

# Display the plot
coordinate_system.show_plot()
