import matplotlib.pyplot as plt 
import numpy as np

# Define the function y = (x + 3)^2
def function(x):
    return (x + 3) ** 2

def derivative(x):
    return 2*(x+3)

def gradient_descent(starting_point, learning_rate, iterations): 
    x_values = []
    y_values = []
    x = starting_point
    for i in range(iterations):
        # Calculate the derivative of the function with respect to x
        gradient = derivative(x)
        # Update x using the gradient and learning rate
        x = x - learning_rate * gradient
        # Store the current x and y values for visualization 
        x_values.append(x)
        y_values.append(function(x))
    return x_values, y_values


# Set the initial parameters
starting_point = 2 
learning_rate = 0.1 
iterations = 50

# Run gradient descent
x_values, y_values = gradient_descent(starting_point, learning_rate, iterations)

# Plot the function
x_vals = np.linspace(-10, 4, 100)
y_vals = function(x_vals)

plt.plot(x_vals, y_vals, label='y = (x + 3)^2')
plt.scatter(x_values, y_values, color='red', label='Gradient Descent Path') 

plt.plot(x_values[-1],y_values[-1],marker='o',color='green')
plt.annotate(f'Point: ({x_values[-1]}, {y_values[-1]})', (x_values[-1], y_values[-1]), textcoords="offset points", xytext=(5,5), ha='center')

plt.title('Gradient Descent Visualization')
plt.xlabel('x') 
plt.ylabel('y') 
plt.legend() 

plt.show()