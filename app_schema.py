import os
import traceback

class App:
    def __init__(self, name, fap_category, fap_version):
        self.name = name
        self.fap_category = fap_category
        self.fap_version = fap_version

def generate_tree_structure(folder_path, output_file):
    with open(output_file, 'w') as f:
        f.write("<ul>\n")
        #f.write("=" * 50 + "\n")
        fap_data = explore_folder(folder_path, f)
        for category, applications in fap_data.items():
            f.write(f"<br>{category}:<br>\n")
            for app in applications:
                f.write(f"    <li> Name: {app.name}</li>\n")
                #f.write(f"    <li> FAP Category: {app.fap_category}</li>\n")
                if app.fap_version:
                    f.write(f"    <li> FAP Version: {app.fap_version}</li>\n")
                f.write("-" * 50 + "\n")
        f.write("</ul>\n")

def explore_folder(folder_path, output_file):
    fap_data = {}
    for root, _, files in os.walk(folder_path):
        if "application.fam" in files:
            fam_file = os.path.join(root, "application.fam")
            with open(fam_file, 'r') as f:
                try:
                    lines = f.readlines()
                    app_data = {}
                    for line in lines:
                        parts = line.strip().split("=")
                        if len(parts) == 2:
                            key, value = parts[0].strip(), parts[1].strip()
                            # Remove double quotes and commas from the beginning and end of the value
                            value = value.strip('",')
                            app_data[key] = value
                    name = app_data.get("name")
                    fap_category = app_data.get("fap_category")
                    fap_version = app_data.get("fap_version", "")  # Get "fap_version" with a default value of an empty string
                    if name is None or fap_category is None:
                        output_file.write(f"Missing data in folder: {root}\n")
                    else:
                        if fap_category not in fap_data:
                            fap_data[fap_category] = []
                        fap_data[fap_category].append(App(name, fap_category, fap_version))
                except Exception as e:
                    output_file.write(f"Error in folder: {root} - {str(e)}\n")
                    traceback.print_exc()
    return fap_data

if __name__ == "__main__":
    starting_folder = r"D:\xxx_flipper_code\firmware\Flipper_MicroSD\applications_user"
    output_filename = "fap_categories.txt"
    generate_tree_structure(starting_folder, output_filename)
    print(f"FAP categories generated and saved in {output_filename}")
