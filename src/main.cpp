#include <SFML/Graphics.hpp>
#include <SFML/OpenGL.hpp>
#include<iostream>
#include<cstdio>
int main()
{
    char path[256];

    FILE *fp = popen("pwd", "r");
    if (fp == nullptr) {
        std::cerr << "Failed to run command\n";
        return 1;
    }

    while (fgets(path, sizeof(path)-1, fp) != nullptr) {
        std::cout << path;
    }

    pclose(fp);

    getchar();
    getchar();
    // 创建SFML窗口
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML with OpenGL");

    // 加载纹理
    sf::Texture texture;
    texture.loadFromFile("./assets/texture1.png");

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // 清除缓冲

        // 绑定纹理
        sf::Texture::bind(&texture);

        // 使用OpenGL代码绘制一个纹理化的四边形
        glBegin(GL_QUADS);
        glTexCoord2f(0, 0); glVertex2f(-0.5f, -0.5f);
        glTexCoord2f(1, 0); glVertex2f( 0.5f, -0.5f);
        glTexCoord2f(1, 1); glVertex2f( 0.5f,  0.5f);
        glTexCoord2f(0, 1); glVertex2f(-0.5f,  0.5f);
        glEnd();

        // 取消绑定纹理
        sf::Texture::bind(NULL);

        window.display();
    }

    return 0;
}
