# Harry's Safe
### Solving algorithm 
For this problem we used the six interrupt pins in the arduino mega simply we used the algorithm of detecting change in the encoder signal A and B and then record pulses by interrupt function that is called at every change of each signal .

We just tripled it to fit the application then we converted the encoder pulses by using the default ppr (pulses per rotation) which is specific for each encoder type and get their ratio *360 

I couldn't test the code online and I couldn't get the encoder to try it but I really hope i works 