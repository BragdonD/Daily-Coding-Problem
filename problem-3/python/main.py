class Node:
    def __init__(self, val, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

    def serialize (self):
        """
        Function to transform a Node into a string
        :exemple {root,{left,{left.left,,},},right} = Node('root', Node('left', Node('left.left')), Node('right'))
        """
        # Empty Node
        if(self.val == None):
            return '';

        output = "{";
        output += self.val;
        output += ',';
        if(self.left != None):
            output += self.left.serialize();
        output += ',';
        if(self.right != None):
            output += self.right.serialize();
        output += "}";
        
        return output;

    def deserialize (self, ser):
        self.ser = ser;
        tokens = self.ser.split(',');
        if (len(tokens[0]) == 0):
            self.ser = self.ser.replace(tokens[0] + ',', '', 1);
            return None;

        if (tokens[0][0] == '}'):
            self.ser = self.ser.replace(tokens[0] + ',', '', 1);
            return None;

        self.ser = self.ser.replace(tokens[0] + ',', '', 1);

        return Node(tokens[0][1:], self.deserialize(self.ser), self.deserialize(self.ser));

                

def main():
    node = Node('root', Node('left', Node('left.left')), Node('right'));
    assert node.deserialize(node.serialize()).left.left.val == 'left.left'

if __name__ == "__main__":
    main()