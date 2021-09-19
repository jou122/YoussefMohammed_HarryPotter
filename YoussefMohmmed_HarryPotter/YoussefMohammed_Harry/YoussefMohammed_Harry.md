# Harry Maze
### Maze solving algorithm 
for this problem we used the simplest oldest maze solving algorithm which is "stick to the right or to the left".

  
Which is pretty simple and obvious you just stick to one direction and always follows it .

So what if this direction isn't available ?

Here is where it gets interesting you rotate by 90 deg and choose the next direction 

Meaning if you choose 
to go right and you suddenly found no right turns what is your next option ? it is going straight and if there is no straight then go left if none is available then you are at a dead end you need to go back

if you are confused lets choose left as our reference 

so now if we can't go left where to go obviously you shouldn't U tern if you have other chooses
so we need to rotate clockwise this time to straight then to right then backward or U-turn 

so why actually does it work ?

two reasons : first in maze you need to move forward or in that case just not backward except at dead ends you might be lucky and fell in a straight maze that will eventually leads you to the end but where is the fun in that

So if you did U-turn the directions you took are actually already  reversed for you so there is no point in reversing them again just stick to your first direction preference and you will automatically follows another direction 

This algorithm originally developed from mazes with walls where you can consider the wall to be a line that leads to the end (a twisted long line but it eventually leads to an end)

this is the simplest algorithm to solve maze it gets complex if you want to calculate and save the shortest path it needs graphs or arrays to save the turns and length of the path 