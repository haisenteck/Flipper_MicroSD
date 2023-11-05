import os

def generate_tree_structure(folder_path, output_file):
    with open(output_file, 'w') as f:
        f.write(f"Tree structure of {folder_path}:\n")
        f.write("=" * 50 + "\n")
        explore_folder(folder_path, f, 0)

def explore_folder(folder_path, output_file, depth):
    indentation = "    " * depth
    for item in os.listdir(folder_path):
        if item == ".git":
            continue  # Skip the .git folder
        item_path = os.path.join(folder_path, item)
        if os.path.isfile(item_path):
            output_file.write(f"{indentation}[File] {item}\n")
        elif os.path.isdir(item_path):
            output_file.write(f"{indentation}[Folder] {item}\n")
            explore_folder(item_path, output_file, depth + 1)

if __name__ == "__main__":
    starting_folder = r"D:\xxx_flipper_code\firmware\Flipper_MicroSD\subghz"
    output_filename = "schema_subg.txt"
    generate_tree_structure(starting_folder, output_filename)
    print(f"Tree structure generated and saved in {output_filename}")
