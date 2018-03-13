#Lem-in 42 Project by overetou & kenguyen

Guide :

A correct map contains 3 parts, in the given order :
	[ant number]
	[rooms]
	[links]

Room field pattern :
	"name coord(x) coord(y)"
Tube field pattern :
	name(1)-name(2)
	
The starting point must be preceded by ##start and the ending point by ##end.

Example :
5
##start
start 0 0
midway 0 1
##end
end 0 2
start-midway
midway-end

Lines preceded by a single # may be placed anywhere in the map.

Usage : ./lem-in < [map] -[param]

Params : -color, -help, -path, -error, -comment.
