from jinja2 import Environment, FileSystemLoader


def main():

    env = Environment(loader=FileSystemLoader('CWebStudio'))
    template = env.get_template('amalgamete.j2')

    complete = template.render(lite=False)
    with open('CWebStudio.c', 'w') as f:
        f.write(complete)

main()


