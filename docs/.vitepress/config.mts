import { defineConfig } from "vitepress"
import { generateSidebar } from "vitepress-sidebar"
import { withMermaid } from "vitepress-plugin-mermaid"

// https://vitepress-sidebar.jooy2.com/getting-started
const vitepressSidebarOptions = {
  excludePattern: ["README.md"],
  excludeFilesByFrontmatterFieldName: "exclude",
  sortMenusByFrontmatterOrder: true,
  useFolderTitleFromIndexFile: true,
  useTitleFromFileHeading: true,
  useTitleFromFrontmatter: true,
}

// https://vitepress.dev/reference/site-config
export default withMermaid(
  defineConfig({
    title: "OpenSolarCoolingHub Documention",
    description: "OpenSolarCoolingHub Documention",

    head: [
      // ["link", { rel: "icon", type: "image/png", href: "favicon.png" }],
      [
        "script",
        {
          async: "",
          src: "https://www.googletagmanager.com/gtag/js?id=G-KJX9KM0WPR",
        },
      ],
      [
        "script",
        {},
        `window.dataLayer = window.dataLayer || [];
        function gtag(){dataLayer.push(arguments);}
        gtag('js', new Date());
        gtag('config', 'G-KJX9KM0WPR');`,
      ],
    ],

    // For hosting on Github pages
    // https://vitepress.dev/guide/deploy#github-pages
    base: "/OpenSolarCoolingHub/",
    vite: {
      publicDir: ".public",
    },
    srcExclude: ["README.md"],
    ignoreDeadLinks: "localhostLinks",

    themeConfig: {
      // https://vitepress.dev/reference/default-theme-config
      nav: [
        { text: "Home", link: "/" },
        { text: "Examples", link: "/markdown-examples" },
      ],

      sidebar: generateSidebar(vitepressSidebarOptions),

      socialLinks: [
        {
          icon: "github",
          link: "https://github.com/EnAccess/OpenSolarCoolingHub",
        },
      ],

      search: {
        provider: "local",
      },
    },
  }),
)
