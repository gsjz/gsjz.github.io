document.addEventListener('DOMContentLoaded', function() {
    if (window.mermaid) {
        // 允许使用 HTML 标签
        window.mermaid.initialize({
            startOnLoad: true,   // 保留默认行为
            securityLevel: 'loose'
        });
    }
});
