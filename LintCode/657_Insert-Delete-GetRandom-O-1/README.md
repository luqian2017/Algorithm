这题最经典的做法还是用unordered_map< int, int > 加一个数组或vector。 
其中underdered_map存储value和index的关系，index就是该value在vector中的位置。 
注意： 
1）getRandom()注意不能%0。因为%0和/0一样都涉及到除0的操作。 
2）在remove()的时候有技巧。这里不能简单的remove掉value对应的元素，因为会留下一个洞。最简单的办法就是把vector的最后一个元素和它互换，然后去掉最后一个元素。 
3) vec.back()是vec[vec.size()-1]这个元素的引用。当然这里要求vec.size()>0。

另外，我觉得还有一种remove()的办法： 就是直接把value这个元素在vec和map中去掉，但是记下vec中的洞的位置。这里需要用另一个vector记录，设为vec_hole。然后每次insert(val)的时候, 用下面的代码就可以了。

if (vec_hole.size() > 0) {
    int hole_index = vec_hole.back();
    vec_hole.pop_back();
    map[value] = hole_index;
    vec[hole_index] = val;
}

但是要注意如果remove末尾的元素就不需要将其加入到vec_hole。下次试试这个方法。

