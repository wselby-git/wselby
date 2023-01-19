! A simple neural network in Fortran

program NeuralNet

implicit none

! Declare the variables
integer :: n_inputs, n_hidden, n_outputs
real, dimension(:), allocatable :: inputs, hidden_layer, output_layer
real, dimension(:,:), allocatable :: weights_input2hidden, weights_hidden2output

! Initialise the network
allocate(inputs(n_inputs))
allocate(hidden_layer(n_hidden))
allocate(output_layer(n_outputs))
allocate(weights_input2hidden(n_inputs, n_hidden))
allocate(weights_hidden2output(n_hidden, n_outputs))

! Read the weights from file
open (1, file="weights.dat")

do i=1, n_inputs
do j=1, n_hidden
read (1, *) weights_input2hidden(i,j)
end do
end do

do k=1, n_hidden
do l=1, n_outputs
read (1, *) weights_hidden2output(k,l)
end do
end do

close (1)

! Forward propagation

do i=1, n_inputs
do j=1, n_hidden
hidden_layer(j) = hidden_layer(j) + inputs(i)*weights_input2hidden(i,j)
end do
end do

do k=1, n_hidden
do l=1, n_outputs
output_layer(l) = output_layer(l) + hidden_layer(k)*weights_hidden2output(k,l)
end do
end do

! Output the results

do i=1, n_outputs
write (6, *) output_layer(i)
end do

! Deallocate memory

deallocate(inputs)
deallocate(hidden_layer)
deallocate(output_layer)
deallocate(weights_input2hidden)
deallocate(weights_hidden2output)

end program NeuralNet
