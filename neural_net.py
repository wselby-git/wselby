# Author: William Selby
# Simple Neural Network in python

import numpy as np

# Define our neural network
class NeuralNetwork:
  def __init__(self, input_nodes, hidden_nodes, output_nodes):
    # Set number of nodes in input, hidden and output layers
    self.input_nodes = input_nodes
    self.hidden_nodes = hidden_nodes
    self.output_nodes = output_nodes

    # Initialize weights
    self.weights_input_to_hidden = np.random.normal(0.0, self.input_nodes**-0.5, 
                                       (self.input_nodes, self.hidden_nodes))

    self.weights_hidden_to_output = np.random.normal(0.0, self.hidden_nodes**-0.5, 
                                       (self.hidden_nodes, self.output_nodes))
    
    # Set activation function
    self.activation_function = lambda x : 1/(1 + np.exp(-x))

  def train(self, inputs_list, targets_list):
    # Convert inputs list to 2d array
    inputs = np.array(inputs_list, ndmin=2).T
    targets = np.array(targets_list, ndmin=2).T
    
    # Forward pass
    # Hidden layer
    hidden_inputs = np.dot(self.weights_input_to_hidden, inputs)
    hidden_outputs = self.activation_function(hidden_inputs)
    
    # Output layer
    final_inputs = np.dot(self.weights_hidden_to_output, hidden_outputs)
    final_outputs = final_inputs
    
    # Backward pass
    # Output errors
    output_errors = targets - final_outputs
    # Hidden errors
    hidden_errors = np.dot(self.weights_hidden_to_output.T, output_errors) 
    
    # Update weights
    self.weights_hidden_to_output += self.learning_rate * np.dot(output_errors * final_outputs * (1 - final_outputs), hidden_outputs.T)
    self.weights_input_to_hidden += self.learning_rate * np.dot(hidden_errors * hidden_outputs * (1 - hidden_outputs), inputs.T)
    
  def run(self, inputs_list):
    # Convert inputs list to 2d array
    inputs = np.array(inputs_list, ndmin=2).T
    
    # Hidden layer
    hidden_inputs = np.dot(self.weights_input_to_hidden, inputs)
    hidden_outputs = self.activation_function(hidden_inputs)
    
    # Output layer
    final_inputs = np.dot(self.weights_hidden_to_output, hidden_outputs)
    final_outputs = final_inputs
    
    return final_outputs
