-- Функция за намиране на изпъкнала обвивка на многоъгълник.

function polygonhull(p)
    local h = {}, i, k
  -- Функция, намираща ориентираното лице на триъгълника abc: число със съответния знак
  -- според това дали abc е отрицателно, положително ориентирана или сълинейна тройка.
    function area(a,b,c)
      return (b.x-a.x)*(c.y-a.y)-(c.x-a.x)*(b.y-a.y)
    end
  -- намиране на индексите на лявата и дясната крайни точки
    local imin, imax = 1, 1
    for i=2,#p do
      if p[i].x < p[imin].x or p[i].x == p[imin].x and p[i].y > p[imin].y then
        imin = i
      end
      if p[i].x > p[imax].x or p[i].x == p[imax].x and p[i].y < p[imax].y then
        imax = i
      end
    end
  -- построяване на горната и долната полуобвивки
    i = imax
    k = imin
    while true do
      table.insert(h,p[i])
      while true do
        i = 1+i%#p
        if i == k then break end
        if 0 < area(p[k],h[#h],p[i]) then
          while #h > 1 and 0 >= area(h[#h-1],h[#h],p[i]) do
            table.remove(h)
          end
          table.insert(h,p[i])
        end
      end
      if k == imax then break end
      k = imax
    end
    return h
  end
  
  -- Пример.
  
  -- Многоъгълник
  poly = {{x=3, y=1}, {x=6, y=5}, {x=7, y=4}, {x=6, y=1}, {x=7, y=0}, {x=11, y=1},
          {x=12, y=3}, {x=11, y=4}, {x=10, y=2}, {x=7, y=1}, {x=9, y=4}, {x=9, y=2},
          {x=10, y=3}, {x=11, y=7}, {x=5, y=6}, {x=2, y=7}, {x=3, y=4}, {x=1, y=2}}
  
  -- Намиране на обвивката
  hull = polygonhull(poly)
  
  -- Извеждане на многоъгълника и обвивката като чертеж – вход за програмата sp
  -- (http://www.math.bas.bg/bantchev/sp)
  print"join )\nwidth 2\ncolour lime\npolygon"
  for i=1,#hull do print(hull[i].x,' ',hull[i].y) end
  print"width .5\ncolour blue\npolygon"
  for i=1,#poly do print(poly[i].x,' ',poly[i].y) end
  print"points"
  for i=1,#poly do print(poly[i].x,' ',poly[i].y) end
  
  -- Примерно пускане на програмата и показване на чертежа
  --       lua polygon-hull.lua | sp svg 10 >p.svg && firefox p.svg &