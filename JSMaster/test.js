// you can define get and set methods for a property 
//   in an object, called accessor methods, which can be inherited
// get methods are called when you want to read the property
// set methods are called to write to the property
// you can write them with or without a backing internal
//   data property
// backing data property could be public or private
//   _ is a hint that the property is private, but it is not enforced
// can choose to only read or write by removing one of them
let accobj = {
  xint: 0,   // like public, read/wrrie
  get x() {return this.xint;},
  set x(val) {this.xint = val;},
  _ypriv: 1,
  get y() {return this._ypriv;},
  set y(val) {this._ypriv = val;}
};
accobj.x = 10;
console.log(accobj.x);
console.log(accobj.xint);   // public, but should be accessed through x
accobj.y = 20;
console.log(accobj.y);
console.log(accobj._ypriv); // still can see it

