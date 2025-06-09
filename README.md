# Rule Of Five Automation
This is a quck and dirty program to automate the rule of five, because I
am growing tired of writing the copy and move functions for my vulakn RAII wrappers.
This will create a simple empty constructor, a copy and move constructor declarations,
a simple copy assignment and move assignment definition, and a simple 
copy and move constructor definition.

This is not meant to be fully automatable, you will need to make adjustments to these functions. Additionally, the program 
will not implement the destructor, only the destructor declaration (for an easy copy and paste).

## Usage
To use, first add the namespace, including the class name and the final scope operator. An example: gf::vk_img::AllocatedImage::

Then, add the class name.

Finally, add the member variables. Variables that would be overwritten on a move will get assigned nullptr.
Replying any letter other than "y" is interpreted as an "n".
When you are done, reply a final "n".

## Known Bugs

The program requires two member variables right now. This is a low priority bug since every class I've written using this has more than one member variable.
