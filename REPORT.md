<<<<<<< HEAD
**Q1. Explain the linking rule $(TARGET): $(OBJECTS) — how does it differ from linking against a library?**
**Answer:** That rule means the final executable target depends directly on object files; the linker simply combines the
 object code into the executable. When linking against a library (static or dynamic), the target depends on the library 
 file (e.g., libmyutils.a or -lmyutils) rather than individual object files; the linker either copies needed object code 
 from the archive into the executable (static) or stores a runtime reference to a shared object (dynamic).

**Q2. What is a git tag and why is it useful in a project? What is the difference between a simple tag and an annotated tag?**
**Answer:** A git tag is a reference to a specific commit in history, usually used to mark releases or stable points.
 It is useful because tags give meaningful names to versions, making them easier to identify than commit hashes.
 A simple (lightweight) tag is just a pointer to a commit without extra metadata, while an annotated tag stores
 additional information such as the tagger’s name, date, and a message. Annotated tags are preferred for official
 releases because they are permanent records in the project history.

**Q3. What is the purpose of creating a "Release" on GitHub? What is the significance of attaching binaries (like your client executable) to it?**
**Answer:** A GitHub release provides a polished, user-friendly way to distribute a project version. It builds on a git
tag but adds a title, description, and optional files. The purpose is to make it easier for others to download and use
stable versions without browsing the commit history. Attaching binaries (like the compiled client executable) is
significant because it allows end users to run the program directly without compiling from source, ensures consistency
across environments, and makes distribution more professional.
=======
**Q1. Explain the linking rule $(TARGET): $(OBJECTS) — how does it differ from linking against a library?**
**Answer:** That rule means the final executable target depends directly on object files; the linker simply combines the
 object code into the executable. When linking against a library (static or dynamic), the target depends on the library 
 file (e.g., libmyutils.a or -lmyutils) rather than individual object files; the linker either copies needed object code 
 from the archive into the executable (static) or stores a runtime reference to a shared object (dynamic).

**Q2. What is a git tag and why is it useful in a project? What is the difference between a simple tag and an annotated tag?**
**Answer:** A git tag is a reference to a specific commit in history, usually used to mark releases or stable points.
 It is useful because tags give meaningful names to versions, making them easier to identify than commit hashes.
 A simple (lightweight) tag is just a pointer to a commit without extra metadata, while an annotated tag stores
 additional information such as the tagger’s name, date, and a message. Annotated tags are preferred for official
 releases because they are permanent records in the project history.

**Q3. What is the purpose of creating a "Release" on GitHub? What is the significance of attaching binaries (like your client executable) to it?**
**Answer:** A GitHub release provides a polished, user-friendly way to distribute a project version. It builds on a git
tag but adds a title, description, and optional files. The purpose is to make it easier for others to download and use
stable versions without browsing the commit history. Attaching binaries (like the compiled client executable) is
significant because it allows end users to run the program directly without compiling from source, ensures consistency
across environments, and makes distribution more professional.
>>>>>>> 4180d81a3151cbba3e899fdfa496490da9cfb1a5
