function love.load()
    local myFont = love.graphics.newFont(45)
    love.graphics.setFont(myFont)
    love.graphics.setColor(0,0,0,255)
    love.graphics.setBackgroundColor(255,153,0)
end

function love.update(dt)
end

function love.draw()
    love.graphics.print('I luv banichka', 200,200)
end