# Restore old style debuginfo creation for rpm >= 4.14.
%undefine _debugsource_packages
%undefine _debuginfo_subpackages

# -*- rpm-spec -*-
BuildRoot:      %_topdir/@CPACK_PACKAGE_FILE_NAME@@CPACK_RPM_PACKAGE_COMPONENT_PART_PATH@
Summary:        @CPACK_PACKAGE_SUMMARY@
Name:           @CPACK_PACKAGE_NAME@
Version:        @CPACK_PACKAGE_VERSION@
Release:        @CPACK_PACKAGE_RELEASE@
License:        @CPACK_PACKAGE_LICENSE@
Group:          @CPACK_PACKAGE_GROUP@
Vendor:         @CPACK_PACKAGE_VENDOR@

BuildRequires:  @CPACK_PACKAGE_BUILD_REQUIRES@

@TMP_RPM_URL@
@TMP_RPM_REQUIRES@
@TMP_RPM_REQUIRES_PRE@
@TMP_RPM_REQUIRES_POST@
@TMP_RPM_REQUIRES_PREUN@
@TMP_RPM_REQUIRES_POSTUN@
@TMP_RPM_PROVIDES@
@TMP_RPM_OBSOLETES@
@TMP_RPM_CONFLICTS@
@TMP_RPM_SUGGESTS@
@TMP_RPM_AUTOPROV@
@TMP_RPM_AUTOREQ@
@TMP_RPM_AUTOREQPROV@
@TMP_RPM_BUILDARCH@
@TMP_RPM_PREFIXES@
@TMP_RPM_EPOCH@

@TMP_RPM_DEBUGINFO@

%define _rpmdir %_topdir/RPMS
%define _srcrpmdir %_topdir/SRPMS
@FILE_NAME_DEFINE@
%define _unpackaged_files_terminate_build 0
@TMP_RPM_SPEC_INSTALL_POST@
@CPACK_RPM_SPEC_MORE_DEFINE@
@CPACK_RPM_COMPRESSION_TYPE_TMP@

%description
@CPACK_RPM_PACKAGE_DESCRIPTION@

# This is a shortcutted spec file generated by CMake RPM generator
# we skip _install step because CPack does that for us.
# We do only save CPack installed tree in _prepr
# and then restore it in build.
%prep
mv $RPM_BUILD_ROOT %_topdir/tmpBBroot

%install
if [ -e $RPM_BUILD_ROOT ];
then
  rm -rf $RPM_BUILD_ROOT
fi
mv %_topdir/tmpBBroot $RPM_BUILD_ROOT

@TMP_RPM_DEBUGINFO_INSTALL@

%clean

%post
@RPM_SYMLINK_POSTINSTALL@
@CPACK_RPM_SPEC_POSTINSTALL@

%posttrans
@CPACK_RPM_SPEC_POSTTRANS@

%postun
@CPACK_RPM_SPEC_POSTUNINSTALL@

%pre
@CPACK_RPM_SPEC_PREINSTALL@

%pretrans
@CPACK_RPM_SPEC_PRETRANS@

%preun
@CPACK_RPM_SPEC_PREUNINSTALL@

%files
%defattr(@TMP_DEFAULT_FILE_PERMISSIONS@,@TMP_DEFAULT_USER@,@TMP_DEFAULT_GROUP@,@TMP_DEFAULT_DIR_PERMISSIONS@)
@CPACK_RPM_INSTALL_FILES@
@CPACK_RPM_ABSOLUTE_INSTALL_FILES@
@CPACK_RPM_USER_INSTALL_FILES@

%changelog
@CPACK_RPM_SPEC_CHANGELOG@

@TMP_OTHER_COMPONENTS@