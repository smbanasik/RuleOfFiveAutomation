# Rule Of Five Automation
This is a simple file to automate the rule of five, because I
am growing tired of writing the copy and move functions for my vulakn RAII wrappers.
This will create a simple empty constructor, a copy and move constructor declarations,
a simple copy assignment and move assignment definition, and a simple 
copy and move constructor definition.

This is not meant to be fully automatable, you may need to make adjustments to these functions. Additionally, the program 
will not implement the destructor, and only implements the destructor declaration (for an easy copy and paste).

## Usage
To use, first add the namespace, including the class name and the final scope operator. An example: gf::vk_img::AllocatedImage::

Then, add the class name.

Finally, add the member variables. Variables that would be overwritten on a move will get assigned nullptr.
Replying any letter other than "y" is interpreted as an "n".
When you are done, reply a final "n".

## Known Bugs

The program will have incorrect output, or it may crash, if you have only one member variable. Fixing this is outside of the scope 
of the program until I have a RAII wrapper that has only one member variable. Add a dummy variable if you need to.

The program has some unpleasent looking spacing at the beginning of the initialization list. This is a low priority issue, since 
your IDE should fix this.
